<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\device;

class DeviceController extends Controller
{
    function getDevices(){

        $devices = device::all();

        return view('dashboard.devices', compact('devices'));
    }
}
