from django.shortcuts import render

# Create your views here.
# View - функции которые вызываются при переходе на некоторый адрес

def index(request):
    return render(request,
        'index.html',
        {}
    )

