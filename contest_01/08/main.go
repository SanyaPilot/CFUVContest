package main

import "fmt"

func main() {
	var a, b, c float64
	fmt.Scanln(&a, &b, &c)
	fmt.Println(max(a, b, c))
}
