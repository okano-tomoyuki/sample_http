import http.server

PORT = 80
# DIRECTORY = "../data"

# class Handler(http.server.SimpleHTTPRequestHandler):
#     def __init__(self, *args, **kwargs):
#         super().__init__(*args, directory=DIRECTORY, **kwargs)

Handler = http.server.SimpleHTTPRequestHandler

with http.server.HTTPServer(("", PORT), Handler) as httpd:
    httpd.serve_forever()