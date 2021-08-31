async def procedure (data):
    data = data + " world"
    print(data)
    return data

v = procedure("hello");