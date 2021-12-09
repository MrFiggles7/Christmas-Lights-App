<template>
  <v-app>
 
    <v-app-bar class="pa-0" absolute prominent app dark color=primary>
     
     
<ul class="lightrope">
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
  <li></li>
</ul>
    
      <v-spacer></v-spacer>
     
      <v-app-bar-title>
      <h1 class="text-h1">Christmas Time</h1>
      </v-app-bar-title>
    

      <v-spacer></v-spacer>


    </v-app-bar>

    <v-main class="fill-height">
      <router-view/>
    </v-main>
  </v-app>
</template>

<script>
export default {
  name: "App",

  data: () => ({
    //
  }),
};
</script>


<style lang="scss">
@import 'sass/main.css';

.v-toolbar__content, .v-toolbar__extension{
  padding: 0 !important;
}
</style>


  
