def orientation(x1,y1,x2,y2,x3,y3)
    val=(y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);
    if val==0
        return 0
    end
    return val>0?1:2
end
