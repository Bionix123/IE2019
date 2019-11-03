<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/oldstuff', function () {
    $hostname =  gethostname();
    $webSocketAdress = gethostbyname($hostname);
    $webSocketPort = "3000";
    $slaveIpAdress =  "192.168.100.25";
    $slaveIpAdress =  "172.20.10.7";
    return view('index', compact("webSocketAdress","webSocketPort","slaveIpAdress"));
});

Route::get('/', function () {
    return view('dashboard.index');
});

Route::get('/devices', 'DeviceController@getDevices');

Route::get('/phone', function () {
    return view('dashboard.phone');
});

Route::get('/settings', function () {
    return view('dashboard.settings');
});

Route::get('/template', function () {
    return view('dashboard.template');
});