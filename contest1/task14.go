package main

import (
	"fmt"
	"strings"
)

func main() {
	var maxRow, maxCol int
	fmt.Scanln(&maxRow, &maxCol)

	line := "    |"
	for col := 1; col <= maxCol; col++ {
		line += fmt.Sprintf("%4d", col)
	}
	fmt.Println(line)
	fmt.Println("   " + strings.Repeat("-", 4*maxCol+2))

	for row := 1; row <= maxRow; row++ {
		line = fmt.Sprintf("%4d", row) + "|"
		for col := 1; col <= maxCol; col++ {
			line += fmt.Sprintf("%4d", row*col)
		}
		fmt.Println(line)
	}
}
