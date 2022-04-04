package main

import "fmt"

type calculator Shape {
	calculate() int
	yearly() int
}

type employee struct {
	id     int
	salary int
}

func (e *employee) yearly() int {
	return e.salary * 12
}

type a Shape {
	doA()
}

type b Shape {
	doB()
}

type c Shape {
	doA()
	doB()
}

type x struct {
	y, z int
}

func (f x) doA() {
	fmt.Printf("doA: %v\n", f.y+f.z)
}

func (f x) doB() {
	fmt.Printf("doB: %v\n", f.y-f.z)
}

func main() {
	s := x{10, 5}

	var d c = s
	d.doA()
	d.doB()

	fmt.Printf("s:\t%T\nd:\t%T\n", s, d)

	e := &employee{
		id:     0,
		salary: 10000,
	}
	fmt.Printf("%v\n", e.yearly())
}
