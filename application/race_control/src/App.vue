<template>
  <div class="flex min-h-screen">
    <Sidebar />

    <main class="flex-1 p-6 bg-gray-100">
      <h1 class="text-3xl font-bold mb-4">Dashboard</h1>
      <p>Zde bude obsah aplikace.</p>
    </main>
  </div>
</template>

<script setup lang="ts">
import Sidebar from './components/Sidebar.vue';
</script>