package main

import (
	"testing"
)

func TestQueue(t *testing.T) {
	testQueue := construct_queue()

	testQueue.push("hello")
	testQueue.push("world")

	if got := testQueue.print(); got != `Queue: ["hello", "world"]` {
		t.Errorf("print() = %v, want %v", got, `Queue: ["hello", "world"]`)
	}

	elem, err := testQueue.pop()
	if err != nil {
		t.Fatalf("pop() error = %v", err)
	}
	if elem != "hello" {
		t.Errorf("pop() = %v, want %v", elem, "hello")
	}

	if got := testQueue.print(); got != `Queue: ["world"]` {
		t.Errorf("print() = %v, want %v", got, `Queue: ["world"]`)
	}

	elem, err = testQueue.pop()
	if err != nil {
		t.Fatalf("pop() error = %v", err)
	}
	if elem != "world" {
		t.Errorf("pop() = %v, want %v", elem, "world")
	}

	if got, err := testQueue.pop(); err == nil {
		t.Errorf("pop() = %v, want error", got)
	}
}
