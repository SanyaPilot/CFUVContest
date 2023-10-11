package main

import "fmt"

func main() {
	var n int
	var x float64
	fmt.Scanln(&n, &x)

	data := make(map[float64]int)
	for i := 0; i < n; i++ {
		var temp float64
		fmt.Scan(&temp)
		data[temp] = 1
	}

	for k := range data {
		s := x - k
		if data[s] == 1 {
			if k <= s {
				fmt.Println(k, s)
			} else {
				fmt.Println(s, k)
			}
			return
		}
	}
	fmt.Println("0 0")
}
