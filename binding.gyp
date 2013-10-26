{
  "targets": [
    {
      "target_name": "libpoker",
      "sources": [ "libpoker.cc" ],
      "include_dirs": [
        "/usr/include/poker-eval/",
      ],
      "link_settings": {
        "libraries": [
          "/usr/lib/libpoker-eval.so"
        ]
      }
    }
  ]
}
