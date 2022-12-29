FROM gcc:4.9
RUN apt-get update -y
RUN apt-get install -y --no-install-recommends
RUN apt-get install make -y
COPY . /prod
WORKDIR /prod/srcs/
RUN make
CMD ["./pipex"]