class StackException(Exception):
    def __init__(self, message):
        self.message = message

class Stack:
    def __init__(self):
        self._data = []
    def peek_at_top(self):
        if not self._data:
            raise StackException('Stack is empty')
        return self._data[-1]
    
    def pop(self):
        if not self._data:
            raise StackException('Cannot pop from empty stack')
        return self._data.pop()

    def push(self, datum):
        self._data.append(datum)
        
    def is_empty(self):
        return self._data == []
        
