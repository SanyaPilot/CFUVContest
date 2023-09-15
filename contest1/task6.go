package main

import "fmt"

var money = [5]int{5000, 1000, 500, 200, 100}

func main() {
	count := [5]int{0, 0, 0, 0, 0}
	var total int
	fmt.Scanln(&total)

	for i, v := range money {
		count[i] = total / v
		total %= v
	}

	fmt.Println(count[0], count[1], count[2], count[3], count[4])
}
