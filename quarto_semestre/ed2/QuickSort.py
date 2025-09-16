import Item

class QuickSort:
    def partition(self, left, right, a):
        i = left
        j = right
        x = a[(i + j) // 2]  # pivô

        while i <= j:
            while a[i].key < x.key:
                i += 1
            while a[j].key > x.key:
                j -= 1
            if i <= j:
                a[i], a[j] = a[j], a[i]  # troca
                i += 1
                j -= 1
        return i, j

    def sort(self, left, right, a):
        if left < right:
            i, j = self.partition(left, right, a)
            if left < j:
                self.sort(left, j, a)
            if i < right:
                self.sort(i, right, a)

    def quicksort(self, a):
        self.sort(0, len(a) - 1, a)
