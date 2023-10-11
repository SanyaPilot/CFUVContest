package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	counts := make(map[int]int)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scan(&temp)
		counts[temp]++

		// Pair found
		if counts[temp] == 2 {
			counts[temp] = 0
		}
	}

	for k := range counts {
		if counts[k] == 1 {
			fmt.Println(k)
			break
		}
	}
}
