package main

import (
	"bufio"
	"fmt"
	"os"
)

func (q *Queue) serialize(filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	curr := q.Head
	for curr != nil {
		file.Write([]byte(curr.Data + "\n"))
		curr = curr.Next
	}

	return nil
}

func deserialize(filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	fmt.Println("Deserialized:")
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}

	return nil
}

func main() {
	q := construct_queue()
	q.push("hello")
	q.push("world")

	fmt.Println("Before operations:", q.print())

	// Сериализация в бинарный файл
	if err := q.serialize("queue.bin"); err != nil {
		fmt.Println("Error serializing to binary:", err)
	}

	// Сериализация в текстовый файл
	if err := q.serialize("queue.txt"); err != nil {
		fmt.Println("Error serializing to text:", err)
	}

	deserialize("queue.bin")

	deserialize("queue.txt")
}
