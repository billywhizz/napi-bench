import { Bench } from './bench.js'
import { createRequire } from "node:module"

const load = createRequire(import.meta.url)

const { sum } = load('./napi-rs-sum.linux-x64-gnu.node');

const bench = new Bench()
const runs = 20000000
const iter = 20

for (let i = 0; i < iter; i++) {
  bench.start('sum_napi-rs')
  for (let j = 0; j < runs; j++) assert(sum(10, 20) === 30)
  bench.end(runs)
}
