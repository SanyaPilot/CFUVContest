package main

import "fmt"

// Начало вставленного кода
func fill(maze [][]int) {
	for y := 0; y < len(maze); y++ {
		for x := 0; x < len(maze[y]); x++ {
			if maze[y][x] == -1 {
				continue
			}

			startX := max(0, x-1)
			startY := max(0, y-1)
			stopX := min(len(maze[y])-1, x+1)
			stopY := min(len(maze)-1, y+1)
			for y1 := startY; y1 <= stopY; y1++ {
				for x1 := startX; x1 <= stopX; x1++ {
					if maze[y1][x1] == -1 {
						maze[y][x]++
					}
				}
			}
		}
	}
}

// Конец

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}
