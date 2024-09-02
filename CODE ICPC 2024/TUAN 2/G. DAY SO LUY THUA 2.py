n = int(input())
a = list(map(int, input().split()))
st = []
for x in a:
    while st and x > st[-1]: st.pop()
    while st and x == st[-1]:
        st.pop()
        x*=2
    st.append(x)
print(st[0])