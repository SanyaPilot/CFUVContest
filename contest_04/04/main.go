package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var target_pclass int
	var target_age float64
	fmt.Scanln(&target_pclass, &target_age)

	answer := map[int][]string{}

	f, _ := os.Open("train.csv")
	r := bufio.NewReader(f)
	r.ReadString('\r')
	for {
		r_line, err := r.ReadString('\r')
		if err == io.EOF {
			break
		}
		line, _ := csv.NewReader(strings.NewReader(r_line)).Read()
		pclass, _ := strconv.Atoi(line[2])
		age, _ := strconv.Atoi(line[5])
		if pclass == target_pclass && line[4] == "female" && float64(age) > target_age {
			answer[age] = append(answer[age], line[3])
		}
	}
	var keys []int
	for k := range answer {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	for _, k := range keys {
		sort.Strings(answer[k])
		for _, name := range answer[k] {
			fmt.Println(name)
		}
	}
}
