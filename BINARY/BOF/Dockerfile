FROM ubuntu:latest

RUN apt-get update && apt-get install -y socat

RUN useradd -m ctfuser

WORKDIR /home/ctfuser

COPY baby_bof /home/ctfuser/baby_bof

RUN echo "IHT{b4by_b0f_1s_3asy_0r_n0t}" > /home/ctfuser/flag.txt

RUN chmod 755 /home/ctfuser/baby_bof
RUN chmod 440 /home/ctfuser/flag.txt
RUN chown root:ctfuser /home/ctfuser/flag.txt

USER ctfuser
EXPOSE 9000

CMD ["socat","TCP-LISTEN:9000,fork","EXEC:/home/ctfuser/baby_bof,pty,stderr,raw"]