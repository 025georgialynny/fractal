import math


def findr(fib):
    bas = 4.184149
    f = float(fib)/3.141592
    f = math.sqrt(f)
    ret = f/bas
    return ret

def dist (pt, bcx, bcy):
    x = math.fabs(pt.xcor())
    y = math.fabs(pt.ycor())
    x =x-bcx
    y = y-bcy
    x = math.pow(x, 2)
    y = math.pow(x, 2)
    hyp = x+y
    hyp = math.sqrt(hyp)
    return hyp

def calL(l, fib):
    if(fib == 55):
        return l
    else:
        comp = findr(fib)
        nl = l*comp
        return int(nl)
        
        
        

def frac(f, times, leng, ls, fn):
    fnew = []
    for x in range(times):
        f[x].hideturtle()
        f[x].pen(pencolor="cyan", pensize=2)
        f[x].speed(0)
        fnew.append(turtle.Turtle())
        f[x].fillcolor("violet")
        
    newcal = 0.0
    calx = 0.0
    bcx = math.fabs(f[0].xcor())
    bcy = math.fabs(f[0].ycor())

    doc = open(fn, "r")
    lines = ""
    lines = doc.readline()
    p = int(lines)
    p1 = int(p/4)
    p3 = p1*3
    lines = doc.readline()
    c=0
    stay = 0.0
    for g in range(p):
        while lines!="0--0--&\n":
            data = lines.split("--")
            if c%3 == 0:
                n = data[0]
                n = float(n)
                if (n>stay):
                    for x in range(times):
                        f[x].left(n)
                else:
                    for x in range(times):
                        f[x].right(n)
                        
            elif c%3 == 1:
                l = int(data[1])
                l = calL(l, leng)
                for x in range(times):
                    f[x].forward(l)
                turtle.update()
                if(g == int(p/2)):
                    newcal = dist(f[0], bcx, bcy)
                    if newcal>=calx:
                        calx = newcal
                        for x in range(times):
                            fnew[x] = f[x].clone()
            else:
                lines = doc.readline()
                stay = n           
            c = c+1
        doc.close()
        doc = open(fn, "r")
        lines = doc.readline()
        lines = doc.readline()
        c=0
        
    if leng == 55:
        for x in range(times):
            fnew[x].right(46)
    else:
        for x in range(times):
            fnew[x].right(46)
    leng = leng-ls
    thrw = leng -ls
    if leng != 0:
        frac(fnew, times, leng, thrw, fn)


import turtle

ofs = input("File name?\n")

times = input("reps?\n")
times = int(times)
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
    
l = 55

frac(f, times, l, 21, ofs)


