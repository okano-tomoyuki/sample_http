FROM python:3.9.18-slim-bullseye

ARG DIST=/usr/local/src
COPY ./src $DIST 
WORKDIR ${DIST}
EXPOSE 80
CMD [ "python", "/usr/local/src/sample_http_server.py" ]