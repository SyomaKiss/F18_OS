./ex4 &
sleep 3
kill -SIGUSR1 $!

./ex4 &
sleep 3
kill -SIGSTOP $!
