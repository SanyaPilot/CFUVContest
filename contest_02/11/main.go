package main

import "fmt"

const rows int = 9
const cols int = 9

// Начало вставленного кода
func isValidSudoku(board [rows][cols]int) bool {
	// Check cols
	for x := 0; x < cols; x++ {
		count := [10]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		for y := 0; y < rows; y++ {
			count[board[y][x]]++
			if count[board[y][x]] > 1 {
				return false
			}
		}
	}

	// Check rows
	for y := 0; y < cols; y++ {
		count := [10]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		for x := 0; x < rows; x++ {
			count[board[y][x]]++
			if count[board[y][x]] > 1 {
				return false
			}
		}
	}

	// Check squares
	for y1 := 0; y1 < rows-3; y1 += 3 {
		for x1 := 0; x1 < cols-3; x1 += 3 {
			count := [10]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			for y2 := y1; y2 < y1+3; y2++ {
				for x2 := x1; x2 < x1+3; x2++ {
					count[board[y2][x2]]++
					if count[board[y2][x2]] > 1 {
						return false
					}
				}
			}
		}
	}
	return true
}

// Конец

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
