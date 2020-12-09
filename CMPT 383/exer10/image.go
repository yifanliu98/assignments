// package main

package exer10

import (
	"image"
	"image/color"
	"image/png"
	"os"
)

func DrawCircle(outerRadius, innerRadius int, outputFile string) {
	circle := image.NewRGBA(image.Rect(0, 0, 200, 200))
	white := color.RGBA{255, 255, 255, 255}
	black := color.RGBA{0, 0, 0, 255}
	for x := 0; x <= 200; x++ {
		for y := 0; y <= 200; y++ {
			distance := (x-100)*(x-100) + (y-100)*(y-100)
			if distance >= (innerRadius*innerRadius) && distance <= (outerRadius*outerRadius) {
				circle.Set(x, y, black)
			} else {
				circle.Set(x, y, white)
			}
		}
	}

	file, err := os.Create(outputFile)
	if err != nil {
		panic(err.Error())
	}
	png.Encode(file, circle)
	defer file.Close()
}

// func main() {
// 	DrawCircle(40, 20, "out.png")
// }
