FROM alpine:3.19.1

WORKDIR /web

RUN apk update && apk add --no-cache python3

COPY portfolio/ /web/

EXPOSE 80

CMD ["python3", "-m", "http.server", "80"]