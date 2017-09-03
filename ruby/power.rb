def power(a,b,mod)
    if b==0
        return 1
    elsif b==1
        return a%mod
    end
    y=power(a,b/2,mod)
    y=(y*y)%mod
    if b%2==0
        return y
    else
        return (y*a)%mod
    end
end
