<template>
  <div class="flex flex-col md:flex-row min-h-screen">
    <Topbar />
    <Sidebar />

    <main class="flex-1 p-6 bg-gray-100">
      <RouterView />
    </main>
  </div>

  <div v-html="icons"></div>
</template>

<script setup lang="ts">
import { RouterView } from 'vue-router';
import Sidebar from './components/layout/Sidebar.vue';
import Topbar from './components/layout/Topbar.vue';
import icons from './assets/icons/icons.svg?raw';
</script>