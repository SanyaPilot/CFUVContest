package main

import "fmt"

func main() {
	var x uint
	fmt.Scanln(&x)
	count := 0
	for x > 1 {
		if x%2 == 0 {
			x /= 2
		} else {
			x = 3*x + 1
		}
		count++
	}

	fmt.Println(count)
}
