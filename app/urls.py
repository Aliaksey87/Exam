from django.urls import path
from app.views import *

urlpatterns = [
    path('', index),
    path('index', index),
    path('sobiraem_sami', sobiraem_sami),
    path('kupit_gotovie', kupit_gotovie),
    path('kontakti', kontakti)
]