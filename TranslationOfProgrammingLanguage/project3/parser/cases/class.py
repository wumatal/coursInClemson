class Mapping:

    def update(self, iterable):
        for item in iterable:
            self.items_list.append(item)
    
    def __init__(self, iterable):
        self.items_list = []
        self.__update(iterable)

