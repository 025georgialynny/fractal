import math

def calN(n, s):
    n2 = n-s
    return n2

def findb(bas):
    f = float(bas)/3.141592
    f = math.sqrt(f)
    return f
def findr(fib, t):
    bas = findb(t)
    f = float(fib)/3.141592
    f = math.sqrt(f)
    ret = f/bas
    return ret

def fibext(scale, fib, thrw):
    if (1-scale == 0):
        return [fib, thrw]
    else:
        for x in range (int(scale)):
            ne = fib - thrw
            fib = fib + ne
            thrw = ne
    return [fib, thrw]

def dist (pt, bcx, bcy):
    x = pt.xcor()
    y = pt.ycor()
    x =x-bcx
    y = y-bcy
    x = math.pow(x, 2)
    y = math.pow(y, 2)
    hyp = x+y
    hyp = math.sqrt(hyp)
    return hyp

def position(t):
    t[0].penup()
    t[0].goto(-650, -450)
    t[0].left(73)
    return t[0]

def calL(l, fib, scale, ct):
    if(fib == ct):
        return l*scale
    else:
        comp = findr(fib, ct)
        nl = l*comp
        return int(nl*scale)
        
        
        

def frac(f, times, leng, ls, fn, ct, scale, bas):
    if(times == 1 & (1-ct == 0)):
        f[0]=position(f).clone()
    fnew = []
    startx = []
    starty = []
    for x in range(times):
        f[x].hideturtle()
        f[x].pendown()
        f[x].hideturtle()
        f[x].fillcolor("white")
        f[x].begin_fill()
        f[x].pen(pencolor="white", pensize=1)
        f[x].speed(0)
        fnew.append(turtle.Turtle())
        fnew[x].hideturtle()
        fnew[x].penup()
        starty.append(f[x].ycor())
        startx.append(f[x].xcor())
        
    newcal = 0.0
    calx = 0.0
    bcx = f[0].xcor()
    bcy = f[0].ycor()
    dire = []

    doc = open(fn, "r")
    lines = ""
    lines = doc.readline()
    c=1
    ca=0
    stay = 0.0
    staythrw = 0.0
    while(ca<6):
        while lines!="0--0--&\n":
            data = lines.split("--")
            if c%3 == 1:
                n = data[0]
                n = float(n)
                staythrw = n
                n = calN(n, stay)
                dire.append(n)
                if (n>0):
                    for x in range(times):
                        f[x].left(n)
                else:
                    for x in range(times):
                        f[x].right(n*-1)
                        
            elif c%3 == 2:
                l = float(data[1])
                l = calL(l, leng, scale, bas)
                for x in range(times):
                    l=int(l)
                    f[x].forward(l)
                turtle.update()
                newcal = dist(f[0], bcx, bcy)
                if newcal>=calx:
                    calx = newcal
                    for x in range(times):
                        fnew[x].setpos(f[x].xcor(), f[x].ycor())
            else:
                lines = doc.readline()
                stay = staythrw
            c = c+1
        ca = ca+1;
        doc.close()
        stay = 60
        doc = open(fn, "r")
        lines = doc.readline()
        c=1
    turn=360/times    
    for x in range(times):
        fnew[x].seth(turn*x)
        fnew[x].right(45*ct)
        if(times == 1):
            fnew[x].left(73)
        f[x].goto(startx[x], starty[x])
        f[x].end_fill()
    leng = leng-ls
    ct = ct+1
    thrw = leng -ls
    if leng != 0:
        frac(fnew, times, leng, thrw, fn, ct, scale, bas)


import turtle

ofs = input("File name?\n")

times = input("reps?\n")
times = int(times)

scale = input("Scale Size: ")
scale = float(scale)

turtle.bgcolor("black")
turtle.setup(1920,1080)
sixty = float(360)/float(times)
n = int(sixty)
while((sixty-n)!=0):
    if times<=25:
        times=times+1
    else:
        times=times-1
    sixty = float(360)/float(times)
    n = int(sixty)

f = []
for x in range(times):
    f.append(turtle.Turtle())

turn = 360/times


for x in range(times):
    if x==0:
        continue
    f[x].left(turn*x)

fi = []
l = 55
thrw = 21
list = fibext(scale, l, thrw)
fib = list[0]
thrw = list[1]
l = fib

frac(f, times, l, thrw, ofs, 1, scale, fib)


