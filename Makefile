CC=cc
V8_VERSION=$(shell node -e "console.log(process.versions.v8.substring(0, process.versions.v8.indexOf('-')))")
URL="https://raw.githubusercontent.com/v8/v8/refs/tags/${V8_VERSION}/include/v8-fast-api-calls.h"

.PHONY: libs bench help

help:
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z0-9\/_\.-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

bench: sum.node napi-sum.node ## run the benchmarks
	npm run bench | tee bench.log
	node chart.js

src/v8-fast-api-calls.h: ## download the v8 fast api headers for current node/v8 version
	echo "downloading src.v8-fast-api-calls.h"
	curl -s -L -o src/v8-fast-api-calls.h ${URL}

node_modules/.bin/node-gyp: ## install node-gyp locally
	npm ci

libs: src/sum.cc src/v8-fast-api-calls.h node_modules/.bin/node-gyp ./node_modules/.bin/napi ## build the ffast binding
	node_modules/.bin/node-gyp --verbose rebuild
	cp -f build/Release/*.node ./
	./node_modules/.bin/napi build --platform --release --strip --js false	

clean: ## clean all the build artifacts except node_modules
	rm -f src/v8-fast-api-calls.h
	rm -fr build
	rm -fr target
	rm -fr node_modules
	rm -f index.d.ts
	rm -f *.node
	rm -f *.log