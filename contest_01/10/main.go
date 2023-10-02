package main

import "fmt"

func main() {
	var raw_swim, raw_wings, raw_neck string
	fmt.Scanln(&raw_swim, &raw_wings, &raw_neck)

	swim := raw_swim == "Да"
	wings := raw_wings == "Да"
	neck := raw_neck == "Да"

	if swim {
		if wings {
			if neck {
				fmt.Println("Утка")
			} else {
				fmt.Println("Пингвин")
			}
		} else {
			if neck {
				fmt.Println("Плезиозавры")
			} else {
				fmt.Println("Дельфин")
			}
		}
	} else {
		if wings {
			if neck {
				fmt.Println("Страус")
			} else {
				fmt.Println("Курица")
			}
		} else {
			if neck {
				fmt.Println("Жираф")
			} else {
				fmt.Println("Кот")
			}
		}
	}
}
