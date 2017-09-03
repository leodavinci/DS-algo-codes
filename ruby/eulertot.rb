def eulertot(x)
    i=2
    result=x
    while i*i<=x do
        if x%i==0
            result=result-result/i
            while x%i==0 do
                x=x/i
            end
        end
        i=i+1
    end
    if x>1
        result=result-result/x
    end
    return result
end
