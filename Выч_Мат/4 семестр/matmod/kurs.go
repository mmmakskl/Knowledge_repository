package main

import (
	"encoding/csv"
	"fmt"
	"math"
	"os"
)

const (
	p1 = 1.0
	p3 = 20.0
	p6 = 0.0
)

func foldP5(x2, p3, p4, p1, p6 float64) float64 {
	a := p3 * p3 * (p6 - x2) * (p6 - x2)

	b := p1 * (p3*p3*p4*p6 - p3*p3*p4*x2 + p3*p3*p4 - 2*p3*p3*p6*x2 + 2*p3*p3*x2*x2 + 2*p3*p4*x2 + p4*x2*x2)

	c := p1 * p1 * (-p3*p3*p4*x2 + p3*p3*p4 + p3*p3*x2*x2 + 2*p3*p4*x2 + p4*x2*x2)

	p5 := (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)

	return p5
}

func foldP2(p1, x2, p4, p5, p6 float64) float64 {
	den := p1 * (p1*x2 + p5*(x2-p6))
	nom := p1*(p4-x2) - p5*(x2-p6)
	p2 := den / (nom * math.Exp(x2/(1+x2/p3)))
	return p2
}

func main() {
	p4vals := []float64{6, 8, 10, 12}

	f, _ := os.Create("bifurcation.csv")
	f2, _ := os.Create("Result.txt")
	defer f.Close()
	defer f2.Close()
	w := csv.NewWriter(f)
	defer w.Flush()
	w.Write([]string{"p4", "p5", "x2", "p2"})

	f2.WriteString("     p4        x2         p5       p2\n")

	for _, p4 := range p4vals {
		f2.WriteString(fmt.Sprintf("\n============= p4 = %.1f =============\n", p4))
		for x2 := 1.0; x2 <= 10.0; x2 += 0.1 {
			p5 := foldP5(x2, p3, p4, p1, p6)
			p2 := foldP2(p1, x2, p4, p5, p6)
			if math.IsNaN(p2) {
				continue
			}
			if math.IsInf(p2, 0) {
				continue
			}
			if p5 < 0 || p2 < 0 {
				continue
			}
			w.Write([]string{fmt.Sprintf("%.2f", p4), fmt.Sprintf("%.7f", p5), fmt.Sprintf("%.2f", x2), fmt.Sprintf("%.7f", p2)})
			f2.WriteString(fmt.Sprintf("p4: %.2f, x2: %.2f, p5: %.7f, p2: %.7f\n", p4, x2, p5, p2))
		}
	}
	fmt.Println("Данные сохранены в bifurcation.csv и result.txt")
}
