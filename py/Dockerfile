FROM python:3.9.18-slim-bullseye

ARG SRC=/usr/local/src
COPY ./src $SRC
WORKDIR ${SRC}
EXPOSE 80
CMD [ "python", "sample_http_server.py" ]