class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


def height(N):
    if N is None:
        return 0
    return N.height


def max(a, b):
    return a if (a > b) else b


def newNode(key):
    node = Node(key)
    return node


def rightRotate(y):
    x = y.left
    T2 = x.right

    x.right = y
    y.left = T2

    y.height = max(height(y.left), height(y.right)) + 1
    x.height = max(height(x.left), height(x.right)) + 1

    return x


def leftRotate(x):
    y = x.right
    T2 = y.left

    y.left = x
    x.right = T2

    x.height = max(height(x.left), height(x.right)) + 1
    y.height = max(height(y.left), height(y.right)) + 1

    return y


def getBalance(N):
    if N is None:
        return 0
    return height(N.left) - height(N.right)


def insert(node, key):
    if node is None:
        return newNode(key)

    if key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)
    else:
        return node

    node.height = 1 + max(height(node.left), height(node.right))

    balance = getBalance(node)

    if balance > 1 and key < node.left.key:
        return rightRotate(node)

    if balance < -1 and key > node.right.key:
        return leftRotate(node)

    if balance > 1 and key > node.left.key:
        node.left = leftRotate(node.left)
        return rightRotate(node)

    if balance < -1 and key < node.right.key:
        node.right = rightRotate(node.right)
        return leftRotate(node)

    return node


def preOrder(root):
    if root:
        print(root.key, end=" ")
        preOrder(root.left)
        preOrder(root.right)


import random

with open("C:\\Users\\buivu\\PycharmProjects\\pythonProject2\\AVL_Height.txt", "w") as fo:
    for f in range(1, 11):
        root = None
        with open(f"C:/Users/buivu/PycharmProjects/pythonProject2/filedata{f}.txt") as fi:
            n = int(fi.readline())
            numbers = list(map(int, fi.readline().split()))

            for num in numbers:
                root = insert(root, num)

            fo.write(str(root.height) + "\n")
