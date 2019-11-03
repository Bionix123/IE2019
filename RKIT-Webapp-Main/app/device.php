<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class device extends Model
{
    public function getOnline($ip_addr){
        
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 6); 
        curl_setopt_array($curl, array(
        CURLOPT_URL => "http://localhost",
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_ENCODING => "",
        CURLOPT_MAXREDIRS => 10,
        CURLOPT_TIMEOUT => 30,
        CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
        CURLOPT_CUSTOMREQUEST => "GET",
        CURLOPT_POSTFIELDS => "{\n\t\"rangeIn\": \"200\",\n\t\"rangeOut\":\"205\"\n}",
        CURLOPT_HTTPHEADER => array(
            "Content-Type: application/json",
            "Postman-Token: c3d4b9e4-23f5-4f74-8bd5-7ff7b0ea9388",
            "cache-control: no-cache"
     ),
    ));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
  $isOnline = false;
} else {
  $isOnline = true;
}


        return $isOnline;

    }
}
