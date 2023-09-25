package main
import (
	"bufio"
	"fmt"
	"os"
)

// Начало вставленного кода
import "strconv"
func isLucky(input string) bool {
	first, second := 0, 0
	for _, sym := range input[:3] {
		temp, _ := strconv.Atoi(string(sym))
		first += temp
	}
	for _, sym := range input[3:] {
		temp, _ := strconv.Atoi(string(sym))
		second += temp
	}
	return first == second
}
// Конец

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky( number[:len(number)-1] ){
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
