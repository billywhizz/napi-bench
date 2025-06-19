import { Bench } from './bench.js'
import { createRequire } from "node:module"

const binding = createRequire(import.meta.url)('./sum.node')

const { sum, sum_slow } = binding

const bench = new Bench()
const runs = 120000000
const iter = 5

for (let i = 0; i < iter; i++) {

  bench.start('sum_slow_ffast')
  for (let j = 0; j < runs; j++) assert(sum_slow(10, 20) === 30)
  bench.end(runs)

  bench.start('sum_ffast')
  for (let j = 0; j < runs; j++) assert(sum(10, 20) === 30)
  bench.end(runs)

}
