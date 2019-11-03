<?php

use Illuminate\Support\Facades\Schema;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateDevicesTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('devices', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->text('name')->nullable();
            $table->longText('switches')->nullable(); //json - count, icons, re-names
            $table->longText('pwms')->nullable(); //json - count, icons, re-names
            $table->longText('sensors')->nullable(); //json - count, icons, re-names
            $table->text('connection_type');
            $table->text('connection_adress');
            $table->boolean('is_camera')->default(false);
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('devices');
    }
}
