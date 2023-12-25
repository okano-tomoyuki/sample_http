FROM debian:bullseye-slim

ARG SRC=/usr/local/src
COPY ./src ${SRC}

RUN apt-get -y update && \
    apt-get -y install build-essential && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* && \
    g++ ${SRC}/sample_http_server.cpp -I${SRC}/include -pthread -o ${SRC}/sample_http_server.out

WORKDIR ${SRC}
EXPOSE 80
CMD [ "/usr/local/src/sample_http_server.out" ]