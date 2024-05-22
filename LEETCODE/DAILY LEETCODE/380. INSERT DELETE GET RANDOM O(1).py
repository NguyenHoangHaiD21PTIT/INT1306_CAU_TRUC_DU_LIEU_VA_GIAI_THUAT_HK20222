import random
class RandomizedSet(object):
    def __init__(self): 
        self.indices = set()
    def insert(self, val):
        if val in self.indices: return False  
        else:
            self.indices.add(val)
            return True
    def remove(self, val):
        if val in self.indices:
            self.indices.remove(val)
            return True
        else: return False  
    def getRandom(self):
        if not self.indices: return None  
        return random.choice(list(self.indices))
if __name__ == "__main__":
    randomizedSet = RandomizedSet()
    print(randomizedSet.insert(1))
    print(randomizedSet.remove(2))
    print(randomizedSet.insert(2))
    print(randomizedSet.getRandom())
    print(randomizedSet.remove(1))
    print(randomizedSet.insert(2))
    print(randomizedSet.getRandom())
