package main

import "fmt"

// Начало вставленного кода
import "math"
func shift(data []int, steps int) {
	temp := make([]int, len(data))
	copy(temp, data)

	realSteps := int(math.Abs(float64(steps))) % len(data)
	if steps < 0 {
		realSteps = -realSteps
	}

	for i := 0; i < len(data); i++ {
		idx := i - realSteps
		if idx < 0 {
			idx = len(data) + idx
		} else if idx >= len(data) {
			idx -= len(data)
		}
		data[i] = temp[idx]
	}
}

// Конец

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
