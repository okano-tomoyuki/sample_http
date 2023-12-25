# simple_http
http client/server を実現するアプローチの検討

複雑なことはしないのでDJangoやFlaskのようなフレームワークを必要としない場合の
PythonでHTTPを利用する際のシンプルなclient&serverライブラリ

[https://docs.python.org/3/library/http.server.html](https://docs.python.org/3/library/http.server.html)

C++でHTTPを利用する際のheader only(ver >= C++11) のclient&serverライブラリ

[https://github.com/yhirose/cpp-httplib](https://github.com/yhirose/cpp-httplib)

apache, nginx, cpp, py いずれかのフォルダ直下で以下のコマンド実行

``` shell
docker compose up -d --build
```

.envファイルに記載されているポートでhttpサーバーがlistenする。
停止する場合は以下のコマンドを実行

``` shell
docker compose down
```