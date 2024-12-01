package main

import (
	"fmt"
	"strings"
)

type Node struct {
	Data string
	Next *Node
}

type Queue struct {
	Head *Node
}

func construct_queue() *Queue {
	return &Queue{}
}

func (q *Queue) push(element string) {
	newNode := &Node{Data: element}

	if q.Head == nil {
		q.Head = newNode
		return
	}

	current := q.Head
	for current.Next != nil {
		current = current.Next
	}
	current.Next = newNode
}

func (q *Queue) pop() (string, error) {
	if q.Head == nil {
		return "", fmt.Errorf("Queue is empty")
	}

	popped := q.Head
	q.Head = q.Head.Next
	return popped.Data, nil
}

func (q *Queue) print() string {
	var sb strings.Builder
	sb.WriteString("Queue: [")
	curr := q.Head
	for curr != nil {
		if curr.Next != nil {
			sb.WriteString(fmt.Sprintf("%q", curr.Data))
			sb.WriteString(", ")
		} else {
			sb.WriteString(fmt.Sprintf("%q", curr.Data))
		}
		curr = curr.Next
	}
	sb.WriteString("]")
	return sb.String()
}
