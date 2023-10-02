package main
import (
	"bufio"
	"fmt"
	"os"
)

// Начало вставленного кода
import (
	"strings"
	"regexp"
)
func isPalindrome(input string) bool {
	max_i := len(input) / 2
	if len(input) % 2 != 0 {
		max_i++
	}
	ok := true
	lowInput := strings.ToLower(input)
	lowInput = regexp.MustCompile(`[~!@#%^&*() ]+`).ReplaceAllString(lowInput, "")
	if (lowInput == "") {
		return true
	}
	for i := 0; i < max_i; i++ {
		if lowInput[i] != lowInput[len(lowInput)-i-1] {
			ok = false
			break
		}
	}
	return ok
}
// Конец

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	//fmt.Println("read")
	if isPalindrome( line[:len(line)-1] ) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
