package main

import "fmt"

func main() {
	oxygen_per_year := 365 * 0.5
	count_topols := int(oxygen_per_year/32 + 1)
	count_dubs := int(oxygen_per_year/20 + 1)
	fmt.Println(oxygen_per_year, count_topols, count_dubs)
}
