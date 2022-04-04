package main

import (
	"fmt"
	"time"
)

type worker struct {
	id   int
	done chan bool
}

func (w *worker) doWork() {
	fmt.Printf("Worker %v doing stuff\n", w.id)
	time.Sleep(time.Second)
	fmt.Printf("Worker %v done\n", w.id)

	w.done <- true
}

func main() {

	// The channel to send to- and receive-from.
	c := make(chan int)

	c <- 1

	// there needs to be a corresponding send from c
	x := <-c
	fmt.Printf("x is: %v\n", x)

	w1 := &worker{
		id:   0,
		done: make(chan bool),
	}

	w2 := &worker{
		id:   1,
		done: make(chan bool),
	}

	// Call worker here
	go w1.doWork()
	go w2.doWork()

	<-w1.done
	<-w2.done
}
