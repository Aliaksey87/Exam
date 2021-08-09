# Create your views here.
# View - функции которые вызываются при переходе на некоторый адрес
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render


def index(request):
    return render(request,
        'index.html',
        {}
    )

def o_chasah(request):
    return render(request,
        'o_chasah.html',
        {}
    )

def sobiraem_sami(request):
    return render(request,
        'sobiraem_sami.html',
        {}
    )

def kupit_gotovie(request):
    return render(request,
        'kupit_gotovie.html',
        {}
    )

def kontakti(request):
    return render(request,
        'kontakti.html',
        {}
    )