package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanln(&n)

	data := make([]float64, n)
	for i := range data {
		fmt.Scan(&data[i])
	}

	buff := make([]any, n)
	for i, v := range data {
		if i == 0 || i == n-1 {
			buff[i] = v
			continue
		}
		buff[i] = (data[i-1] + v + data[i+1]) / 3
	}
	fmt.Println(buff...)
}
