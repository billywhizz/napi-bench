{
  "targets": [
    {
      "target_name": "napi-sum",
      "sources": [
        "src/napi-sum.cpp"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native"
      ]
    },
    {
      "target_name": "sum",
      "sources": [
        "src/sum.cc"
      ],
      "cflags_cc": [
        "-O3",
        "-march=native",
        "-mtune=native",
        "-Wcast-function-type"
      ],
      "include_dirs": [],
      "libraries": []
    }
  ]
}
